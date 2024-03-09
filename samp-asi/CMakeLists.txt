set(SAMPASISRCS
  main.cpp
  main.h
)
APPEND_PLATFORM_SOURCES(SAMPASISRCS)
source_group(cefsimple FILES ${SAMPASISRCS})

set(SAMPASISRCS
  ${SAMPASISRCS}
)

ADD_LOGICAL_TARGET("libcef_lib" "${CEF_LIB_DEBUG}" "${CEF_LIB_RELEASE}")

set(ASI_TARGET "anothersampcef")
# add_executable(${CEF_TARGET} WIN32 ${CEFSIMPLE_SRCS})

add_library(${ASI_TARGET} SHARED ${SAMPASISRCS})
add_dependencies(${ASI_TARGET} libcef_dll_wrapper)
target_link_libraries(${ASI_TARGET} libcef_lib libcef_dll_wrapper)
target_include_directories(${ASI_TARGET} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../shared
  ${_CEF_ROOT}
)
set_target_properties(${ASI_TARGET} PROPERTIES CXX_STANDARD 17)
set_target_properties(${ASI_TARGET} PROPERTIES SUFFIX ".asi")
COPY_FILES(${ASI_TARGET} "${CEF_BINARY_FILES}" "${CEF_BINARY_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/CEF")