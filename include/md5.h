#ifndef MD5_H
#define MD5_H

#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MD5_DIGEST_SIZE 16
#define MD5_BLOCK_SIZE 64

struct md5_ctx
{
	uint32_t A;
	uint32_t B;
	uint32_t C;
	uint32_t D;

	uint32_t total[2];
	uint32_t buflen;     /* ≥ 0, ≤ 128 */
	uint32_t buffer[32]; /* 128 bytes; */
};

extern void md5_init_ctx(struct md5_ctx* ctx);
extern void md5_process_block(const void* buffer, size_t len, struct md5_ctx* ctx);
extern void md5_process_bytes(const void* buffer, size_t len, struct md5_ctx* ctx);
extern void* md5_buffer(const char* buffer, size_t len, void* resblock);
extern void* md5_finish_ctx(struct md5_ctx* ctx, void* resbuf);
extern void* md5_read_ctx(const struct md5_ctx* ctx, void* resbuf);
extern int md5_stream(FILE* stream, void* resblock);

#ifdef __cplusplus
}
#endif

#endif /* MD5_H */