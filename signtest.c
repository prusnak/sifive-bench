#include <stdio.h>
#include "ed25519.h"

void handle_m_ext_interrupt() { }
void handle_m_time_interrupt() { }

ed25519_secret_key sk;
ed25519_public_key pk;
ed25519_signature RS;

int main()
{
    char msg[32];
    for (int i = 0; i < 32; i++) { msg[i] = i; }
    for (int i = 0; i < 32; i++) { sk[i] = i; }

    ed25519_publickey(sk, pk);

    for (;;) {
        printf("signing 100 times ...\n");
        for (int i = 0; i < 100; i++) {
            ed25519_sign(msg, 32, sk, pk, RS);
        }
        printf("done\n");
    }

    return 0;
}
