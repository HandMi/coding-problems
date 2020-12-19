cc_library(
    name = "PEP2",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP2_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP2",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP2_bin",
    deps = [
        "//ProjectEulerPlus/PEP2",
    ],
)
