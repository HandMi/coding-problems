cc_library(
    name = "CF1360E",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1360E_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF1360E",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF1360E_bin",
    deps = [
        "//Codeforces/CF1360E",
    ],
)
