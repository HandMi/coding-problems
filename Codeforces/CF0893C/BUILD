cc_library(
    name = "CF0893C",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF0893C_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF0893C",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF0893C_bin",
    deps = [
        "//Codeforces/CF0893C",
    ],
)
