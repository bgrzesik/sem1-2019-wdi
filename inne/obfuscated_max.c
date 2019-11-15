//
// Created by Bartłomiej Grzesik on 15/11/2019.
//

#include <stdio.h>

main(int argc)
{
    return argc < 1 << 9 ? argc == 1 ? ({
        printf("%d", ({
            int a;
            scanf("%d\n", &a);
            ({
                int x = main(argc << 1);
                x > a ? x : a;
            });
        }));
        0;
    }) : ({
        int a;
        scanf("%d\n", &a);
        ({
            int x = main(argc << 1);
            x > a ? x : a;
        });
    }) : ({
        int a;
        scanf("%d\n", &a);
        a;
    });
}