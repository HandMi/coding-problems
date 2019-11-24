cc_library(
    name = "1257D",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "1257D_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//1257D",
        "@gtest//:gtest_main",
    ],
)
