cc_library(
    name = "CF618D",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF618D_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF618D",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "CF618D_bin",
    deps = [
        "//Codeforces/CF618D",
    ],
)
