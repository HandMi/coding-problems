cc_library(
    name = "PEP015",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP015_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP015",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP015_bin",
    deps = [
        "//ProjectEulerPlus/PEP015",
    ],
)
