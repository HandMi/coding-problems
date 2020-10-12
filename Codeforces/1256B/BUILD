cc_library(
    name = "1256B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "1256B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//1256B",
        "@gtest//:gtest_main",
    ],
)
