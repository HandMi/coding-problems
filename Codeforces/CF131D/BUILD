cc_library(
    name = "CF131D",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF131D_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF131D",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "CF131D_bin",
    deps = [
        "//Codeforces/CF131D",
    ],
)