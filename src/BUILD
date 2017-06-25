cc_library(
  name = "timer",
  srcs = ["timer.cpp"],
  hdrs = ["timer.h"],
)

cc_library(
  name = "helpers",
  srcs = ["helpers.cpp"],
  hdrs = ["helpers.h"],
)

cc_binary(
  name = "main",
  srcs = ["main.cpp"],
  deps = [
    ":timer",
    ":helpers",
    "//src/matrix:matrix",
  ],
)
