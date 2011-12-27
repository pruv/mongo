/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 2008-2011 WiredTiger, Inc.
 *	All rights reserved.
 */

#include "wt_internal.h"

static int
__bm_invalid(WT_SESSION_IMPL *session)
{
	__wt_errx(session, "invalid block manager handle");
	return (WT_ERROR);
}

/*
 * __wt_bm_addr_valid --
 *	Return if an address cookie is valid.
 */
int
__wt_bm_addr_valid(
    WT_SESSION_IMPL *session, const uint8_t *addrbuf, uint32_t addrbuf_size)
{
	WT_BLOCK *block;

	if ((block = session->btree->block) == NULL)
		return (__bm_invalid(session));

	return (__wt_block_addr_valid(session, block, addrbuf, addrbuf_size));
}

/*
 * __wt_bm_addr_string
 *	Return a printable string representation of an address cookie.
 */
int
__wt_bm_addr_string(WT_SESSION_IMPL *session,
    WT_BUF *buf, const uint8_t *addrbuf, uint32_t addrbuf_size)
{
	WT_BLOCK *block;

	if ((block = session->btree->block) == NULL)
		return (__bm_invalid(session));

	return (
	    __wt_block_addr_string(session, block, buf, addrbuf, addrbuf_size));
}

/*
 * __wt_bm_create --
 *	Create a new file.
 */
int
__wt_bm_create(WT_SESSION_IMPL *session, const char *filename)
{
	return (__wt_block_create(session, filename));
}

/*
 * __wt_bm_open --
 *	Open a file.
 */
int
__wt_bm_open(WT_SESSION_IMPL *session,
    const char *filename, const char *config, int salvage)
{
	return (__wt_block_open(
	    session, filename, config, salvage, &session->btree->block));
}

/*
 * __wt_bm_close --
 *	Close a file.
 */
int
__wt_bm_close(WT_SESSION_IMPL *session)
{
	WT_BLOCK *block;

	if ((block = session->btree->block) == NULL)
		return (__bm_invalid(session));

	return (__wt_block_close(session, block));
}

/*
 * __wt_bm_free --
 *	Free a chunk of space to the underlying file.
 */
int
__wt_bm_free(
    WT_SESSION_IMPL *session, const uint8_t *addrbuf, uint32_t addrbuf_size)
{
	WT_BLOCK *block;

	if ((block = session->btree->block) == NULL)
		return (__bm_invalid(session));

	return (__wt_block_free_buf(session, block, addrbuf, addrbuf_size));
}

/*
 * __wt_bm_read --
 *	Read a address cookie-referenced block into a buffer.
 */
int
__wt_bm_read(WT_SESSION_IMPL *session,
    WT_BUF *buf, const uint8_t *addrbuf, uint32_t addrbuf_size)
{
	WT_BLOCK *block;

	if ((block = session->btree->block) == NULL)
		return (__bm_invalid(session));

	return (
	    __wt_block_read_buf(session, block, buf, addrbuf, addrbuf_size));
}

/*
 * __wt_bm_write --
 *	Write a buffer into a block, returning the block's address cookie.
 */
int
__wt_bm_write(WT_SESSION_IMPL *session,
    WT_BUF *buf, uint8_t *addrbuf, uint32_t *addrbuf_size)
{
	WT_BLOCK *block;

	if ((block = session->btree->block) == NULL)
		return (__bm_invalid(session));

	return (
	    __wt_block_write_buf(session, block, buf, addrbuf, addrbuf_size));
}

/*
 * __wt_bm_stat --
 *	Block-manager statistics.
 */
int
__wt_bm_stat(WT_SESSION_IMPL *session)
{
	WT_BLOCK *block;

	if ((block = session->btree->block) == NULL)
		return (__bm_invalid(session));

	__wt_block_stat(session, block);
	return (0);
}

/*
 * __wt_bm_salvage_start --
 *	Start a block manager salvage.
 */
int
__wt_bm_salvage_start(WT_SESSION_IMPL *session)
{
	WT_BLOCK *block;

	if ((block = session->btree->block) == NULL)
		return (__bm_invalid(session));

	return (__wt_block_salvage_start(session, block));
}

/*
 * __wt_bm_salvage_next --
 *	Return the next block from the file.
 */
int
__wt_bm_salvage_next(WT_SESSION_IMPL *session,
    WT_BUF *buf, uint8_t *addrbuf, uint32_t *addrbuf_lenp, int *eofp)
{
	WT_BLOCK *block;

	if ((block = session->btree->block) == NULL)
		return (__bm_invalid(session));

	return (__wt_block_salvage_next(
	    session, block, buf, addrbuf, addrbuf_lenp, eofp));
}

/*
 * __wt_bm_salvage_end --
 *	End a block manager salvage.
 */
int
__wt_bm_salvage_end(WT_SESSION_IMPL *session, int success)
{
	WT_BLOCK *block;

	if ((block = session->btree->block) == NULL)
		return (__bm_invalid(session));

	return (__wt_block_salvage_end(session, block, success));
}

/*
 * __wt_bm_verify_start --
 *	Start a block manager salvage.
 */
int
__wt_bm_verify_start(WT_SESSION_IMPL *session, int *emptyp)
{
	WT_BLOCK *block;

	if ((block = session->btree->block) == NULL)
		return (__bm_invalid(session));

	return (__wt_block_verify_start(session, block, emptyp));
}

/*
 * __wt_bm_verify_end --
 *	End a block manager salvage.
 */
int
__wt_bm_verify_end(WT_SESSION_IMPL *session)
{
	WT_BLOCK *block;

	if ((block = session->btree->block) == NULL)
		return (__bm_invalid(session));

	return (__wt_block_verify_end(session, block));
}

/*
 * __wt_bm_verify_addr --
 *	Verify an address.
 */
int
__wt_bm_verify_addr(WT_SESSION_IMPL *session,
     const uint8_t *addrbuf, uint32_t addrbuf_size)
{
	WT_BLOCK *block;

	if ((block = session->btree->block) == NULL)
		return (__bm_invalid(session));

	return (__wt_block_verify_addr(session, block, addrbuf, addrbuf_size));
}
