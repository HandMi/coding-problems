cc_library(
    name = "PEP006",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP006_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP006",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP006_bin",
    deps = [
        "//ProjectEulerPlus/PEP006",
    ],
)
