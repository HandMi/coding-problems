cc_library(
    name = "1244C",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "1244C_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//1244C",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "1244C_exe",
    deps = [
        "//1244C",
    ],
)