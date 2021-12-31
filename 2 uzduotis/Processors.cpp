//
// Created by 37067 on 12/15/2021.
//

#include "Processors.h"
Processors::Processors(int cnt): Item( cnt, "vnt", "Procesoriai") {
    setPrice(5,20);
}
Processors::Processors(): Item( 0, "vnt", "Procesoriai") {
    setPrice(5,20);
    int n=100+rand()% 401;
    increaseCount(n);
}