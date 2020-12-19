cc_library(
    name = "CF292B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF292B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF292B",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "CF292B_bin",
    deps = [
        "//Codeforces/CF292B",
    ],
)