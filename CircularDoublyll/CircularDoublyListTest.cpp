#include <deepstate/DeepState.hpp>
#include "circulardoublylist.h"

using namespace deepstate;

TEST(CircularDoublyList, ComprehensiveTest) {
    CircularDoublyList list;
    int numOperations = DeepState_IntInRange(1, 100);
    LOG(INFO) << "Performing " << numOperations << " operations on the list.";

    for (int i = 0; i < numOperations; i++) {
        int operation = DeepState_IntInRange(1, 6);
        int value = DeepState_Int();

        switch (operation) {
            case 1:
                list.insertBegin(value);
                break;
            case 2:
                list.insertEnd(value);
                break;
            case 3:
                if (list.getCount() > 0) {
                    int position = DeepState_IntInRange(1, list.getCount() + 1);
                    list.insertAtPosition(value, position);
                }
                break;
            case 4:
                if (list.getCount() > 0) {
                    int position = DeepState_IntInRange(1, list.getCount());
                    list.deleteAtPosition(position);
                }
                break;
            case 5:
                list.searchElement(value);
                break;
            case 6:
                list.reverseList();
                break;
        }
    }

    LOG(INFO) << "Displaying final list:";
    list.displayList(); // This just logs output
}
