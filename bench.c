#include <stdio.h>
#include <string.h>

#include "ed25519.h"

void handle_m_ext_interrupt() { }
void handle_m_time_interrupt() { }

void bench_sign(void)
{
    ed25519_secret_key sk;
    ed25519_public_key pk;
    ed25519_signature RS;
    char msg[32];

    for (size_t i = 0; i < sizeof(msg); i++) {
        msg[i] = i * 1103515245;
    }
    memcpy(sk, "\xc5\x5e\xce\x85\x8b\x0d\xdd\x52\x63\xf9\x68\x10\xfe\x14\x43\x7c\xd3\xb5\xe1\xfb\xd7\xc6\xa2\xec\x1e\x03\x1f\x05\xe8\x6d\x8b\xd5", 32);

    ed25519_publickey(sk, pk);

    printf("benching ed25519_sign:\n");
    for (int j = 1; j <= 10; j++) {
        for (int i = 0; i < 100; i++) {
            ed25519_sign(msg, 32, sk, pk, RS);
        }
        printf("%d\n", j * 100);
    }
}

int main()
{
    bench_sign();

    return 0;
}
