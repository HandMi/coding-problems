cc_library(
    name = "CF0002B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF0002B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF0002B",
        "@gtest//:gtest_main",
    ],
)
