add_library(LibraryCore STATIC
    Source/Core/Core.cpp
    Source/Core/Person.cpp
    Source/Core/Library.cpp
)

target_include_directories(LibraryCore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Source
)

