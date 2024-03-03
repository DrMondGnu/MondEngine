//
// Created by MondGnu on 2/27/2024.
//

#include "engine/event/event.h"


namespace mondengine {


} // event
// mondengine

fmt::basic_appender<char> fmt::formatter<mondengine::Event>::format(mondengine::Event &e, fmt::format_context &ctx) const
{
    return formatter<std::string>::format(e.ToString(), ctx);
}