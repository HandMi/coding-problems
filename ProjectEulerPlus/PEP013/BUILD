cc_library(
    name = "PEP013",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP013_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP013",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP013_bin",
    deps = [
        "//ProjectEulerPlus/PEP013",
    ],
)
