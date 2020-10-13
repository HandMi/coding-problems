cc_library(
    name = "CF1257E",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1257E_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF1257E",
        "@gtest//:gtest_main",
    ],
)
