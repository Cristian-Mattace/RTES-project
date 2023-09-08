cc_test(
    name = "singly_linked_list_test",
    srcs = ["SinglyLinkedListTest.cpp"],
    deps = ["@com_google_googletest//:gtest_main", "//src/singly-linked-list:singly-linked-list", "//src/singly-linked-list/node:node"],
)

cc_test(
    name = "static_linked_list_test",
    srcs = ["StaticLinkedListTest.cpp"],
    deps = ["@com_google_googletest//:gtest_main", "//src/singly-linked-list:static-linked-list", "//src/singly-linked-list/node:node"],
)

cc_test(
    name = "groups_linked_list_test",
    srcs = ["GroupsLinkedListTest.cpp"],
    deps = ["@com_google_googletest//:gtest_main", "//src/singly-linked-list:singly-linked-list", "//src/singly-linked-list:groups-linked-list", "//src/singly-linked-list/node:node"],
)

cc_test(
    name = "queue_lib_test",
    srcs = ["QueueLibTest.cpp"],
    deps = ["@com_google_googletest//:gtest_main", "//src:queue-lib", "//src/singly-linked-list:static-linked-list", "//src/singly-linked-list:singly-linked-list", "//src/singly-linked-list:groups-linked-list", "//src/singly-linked-list/node:node"],
)