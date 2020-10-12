cc_library(
    name = "1256E",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "1256E_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/1256E",
        "@gtest//:gtest_main",
    ],
)
