IF(MSVC)
    SET(CMAKE_CXX_FLAGS "/EHsc")
ENDIF(MSVC)

ADD_LOGICAL_TARGET("libcef_lib" "${CEF_LIB_DEBUG}" "${CEF_LIB_RELEASE}")

set(ASI_TARGET "anothersampcef")
# add_executable(${CEF_TARGET} WIN32 ${CEFSIMPLE_SRCS})

add_library(${ASI_TARGET} SHARED main.cpp)
add_dependencies(${ASI_TARGET} libcef_dll_wrapper )
target_link_libraries(${ASI_TARGET} libcef_lib libcef_dll_wrapper)
target_include_directories(${ASI_TARGET} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../shared
  ${_CEF_ROOT}/
  ${DIRECTX9_SDK_DIR}/Include
)
set_target_properties(${ASI_TARGET} PROPERTIES CXX_STANDARD 17)
set_target_properties(${ASI_TARGET} PROPERTIES SUFFIX ".asi")