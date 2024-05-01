//
// Created by MondGnu on 5/1/2024.
//

#ifndef MONDENGINE_FILEREADER_H
#define MONDENGINE_FILEREADER_H

#include <filesystem>
#include <fstream>

namespace mondengine {

    class FileReader {
    protected:
        using path = std::filesystem::path;
    public:

        /**
         * Reads bytes
         * @param out where the bytes will be read to
         * @param size amount to read
         */
        virtual void ReadBytes(char* out, std::streamsize size) = 0;

        /**
         * Reads into a string
         * @param size amount to read
         * @return string with read bytes
         */
        virtual std::string ReadString(std::streamsize size) = 0;

        virtual std::string ReadAll() = 0;

        virtual void SetPos(std::streamoff pos) = 0;

        virtual void Open(path path) = 0;

    };

    class StreamFileReader : public FileReader {
    public:
        explicit StreamFileReader(const path& path);

        void ReadBytes(char *out, std::streamsize size) override;

        std::string ReadString(std::streamsize size) override;

        std::string ReadAll() override;

        void SetPos(std::streamoff pos) override;

        void Open(path path) override;

    protected:
        std::ifstream stream;
    };

} // mondengine

#endif //MONDENGINE_FILEREADER_H
