#include "Storage.h"
Storage::Storage(int cnt): Item(cnt,"Tb", "Storage") {
    setPrice(5,20);

}
Storage::Storage(): Item(0,"Tb", "Storage") {
    setPrice(5, 20);
    int n = 5000 + rand() % 10001;
    increaseCount(n);
}