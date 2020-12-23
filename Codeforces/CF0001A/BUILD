cc_library(
    name = "CF0001A",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF0001A_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF0001A",
        "@gtest//:gtest_main",
    ],
)
