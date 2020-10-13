cc_library(
    name = "CF1256E",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1256E_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF1256E",
        "@gtest//:gtest_main",
    ],
)
