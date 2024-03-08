#dll copy
function(copy_dlls_to_target target_name dll_list)
    copy_dlls_to_target_when(${target_name} ${target_name} ${dll_list})
endfunction(copy_dlls_to_target)

function(copy_dlls_to_target_when target_name when dll_list)
    # Check if target exists
    if (NOT TARGET ${target_name})
        message(ERROR "Target '${target_name}' does not exist")
        return()
    endif ()
    if (NOT TARGET ${when})
        message(ERROR "Target '${when}' does not exist")
        return()
    endif ()

    # Get the target binary directory
    get_target_property(target_binary_dir ${target_name} BINARY_DIR)

    # Check if directory exists
    if (NOT EXISTS ${target_binary_dir})
        message(ERROR "Target binary directory '${target_binary_dir}' does not exist")
        return()
    endif ()
    # Loop through each DLL and copy it
    foreach (dll ${dll_list})

        message(STATUS "Adding '${dll}' to '${target_binary_dir}'")
        # execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different
        #       ${dll} ${target_binary_dir})
        add_custom_command(
                TARGET ${when}
                POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${dll}
                ${target_binary_dir}
        )
    endforeach ()
endfunction(copy_dlls_to_target_when)
