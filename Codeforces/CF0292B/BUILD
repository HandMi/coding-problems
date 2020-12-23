cc_library(
    name = "CF0292B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF0292B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF0292B",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "CF0292B_bin",
    deps = [
        "//Codeforces/CF0292B",
    ],
)
