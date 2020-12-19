cc_library(
    name = "PEP1",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP1_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP1",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP1_bin",
    deps = [
        "//ProjectEulerPlus/PEP1",
    ],
)
