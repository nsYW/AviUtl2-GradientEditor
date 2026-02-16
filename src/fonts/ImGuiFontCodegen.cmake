add_executable(binary_to_compressed_c ${IMGUI_SOURCE}/misc/fonts/binary_to_compressed_c.cpp)

set(SOURCE_FONT_FILE "${CMAKE_CURRENT_LIST_DIR}/MaterialSymbolsOutlined[FILL,GRAD,opsz,wght].ttf")

set(GENERATED_CPP "${CMAKE_CURRENT_LIST_DIR}/material_symbols.cpp")

add_custom_command(
    OUTPUT ${GENERATED_CPP}
    COMMAND binary_to_compressed_c
            "${SOURCE_FONT_FILE}"
            material_symbols
            > "${GENERATED_CPP}"
    DEPENDS binary_to_compressed_c "${SOURCE_FONT_FILE}"
    CODEGEN
)
