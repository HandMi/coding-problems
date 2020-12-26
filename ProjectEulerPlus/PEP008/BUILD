cc_library(
    name = "PEP008",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP008_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP008",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP008_bin",
    deps = [
        "//ProjectEulerPlus/PEP008",
    ],
)
