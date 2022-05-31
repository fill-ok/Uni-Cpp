   // case 2:
        //     //  range based for-loop
        //     for(int it: v) {
        //         int i = &it - &v[0];

        //         if(it == search_term){
        //             return i;
        //         } else if(i+1 == v.size()){
        //             return -1;
        //         }
        //     }
        //     break;
        
        // case 3:
        //     // for_each + lambda
        //     for_each(v.begin(), v.end(), [&v,&search_term](auto const& it){
        //         auto i = &it -&v[0];

        //         if(it == search_term){
        //             return i;
        //         } else if(i+1 == v.size()){
        //             return -1;
        //         }
        //     });
        //     break;