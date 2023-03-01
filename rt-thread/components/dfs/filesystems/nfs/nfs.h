/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */
/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _NFS_H_RPCGEN
#define _NFS_H_RPCGEN

#include <rpc/rpc.h>

#ifdef __cplusplus
extern "C" {
#endif

/* This file is copied from RFC1813
 * Copyright 1995 Sun Micrososystems (I assume)
 */
#define NFS3_FHSIZE 64
#define NFS3_COOKIEVERFSIZE 8
#define NFS3_CREATEVERFSIZE 8
#define NFS3_WRITEVERFSIZE 8
#define ACCESS3_READ 0x0001
#define ACCESS3_LOOKUP 0x0002
#define ACCESS3_MODIFY 0x0004
#define ACCESS3_EXTEND 0x0008
#define ACCESS3_DELETE 0x0010
#define ACCESS3_EXECUTE 0x0020
#define FSF3_LINK 0x0001
#define FSF3_SYMLINK 0x0002
#define FSF3_HOMOGENEOUS 0x0008
#define FSF3_CANSETTIME 0x0010

typedef unsigned long long uint64;

typedef long long int64;

typedef u_long uint32;

typedef long int32;

typedef char *filename3;

typedef char *nfspath3;

typedef uint64 fileid3;

typedef uint64 cookie3;

typedef char cookieverf3[NFS3_COOKIEVERFSIZE];

typedef char createverf3[NFS3_CREATEVERFSIZE];

typedef char writeverf3[NFS3_WRITEVERFSIZE];

typedef uint32 uid3;

typedef uint32 gid3;

typedef uint64 size3;

typedef uint64 offset3;

typedef uint32 mode3;

typedef uint32 count3;

enum nfsstat3 {
    NFS3_OK = 0,
    NFS3ERR_PERM = 1,
    NFS3ERR_NOENT = 2,
    NFS3ERR_IO = 5,
    NFS3ERR_NXIO = 6,
    NFS3ERR_ACCES = 13,
    NFS3ERR_EXIST = 17,
    NFS3ERR_XDEV = 18,
    NFS3ERR_NODEV = 19,
    NFS3ERR_NOTDIR = 20,
    NFS3ERR_ISDIR = 21,
    NFS3ERR_INVAL = 22,
    NFS3ERR_FBIG = 27,
    NFS3ERR_NOSPC = 28,
    NFS3ERR_ROFS = 30,
    NFS3ERR_MLINK = 31,
    NFS3ERR_NAMETOOLONG = 63,
    NFS3ERR_NOTEMPTY = 66,
    NFS3ERR_DQUOT = 69,
    NFS3ERR_STALE = 70,
    NFS3ERR_REMOTE = 71,
    NFS3ERR_BADHANDLE = 10001,
    NFS3ERR_NOT_SYNC = 10002,
    NFS3ERR_BAD_COOKIE = 10003,
    NFS3ERR_NOTSUPP = 10004,
    NFS3ERR_TOOSMALL = 10005,
    NFS3ERR_SERVERFAULT = 10006,
    NFS3ERR_BADTYPE = 10007,
    NFS3ERR_JUKEBOX = 10008
};
typedef enum nfsstat3 nfsstat3;

enum ftype3 {
    NFS3REG = 1,
    NFS3DIR = 2,
    NFS3BLK = 3,
    NFS3CHR = 4,
    NFS3LNK = 5,
    NFS3SOCK = 6,
    NFS3FIFO = 7
};
typedef enum ftype3 ftype3;

enum stable_how {
    UNSTABLE = 0,
    DATA_SYNC = 1,
    FILE_SYNC = 2
};
typedef enum stable_how stable_how;

enum createmode3 {
    UNCHECKED = 0,
    GUARDED = 1,
    EXCLUSIVE = 2
};
typedef enum createmode3 createmode3;

struct specdata3 {
    uint32 specdata1;
    uint32 specdata2;
};
typedef struct specdata3 specdata3;

struct nfs_fh3 {
    struct {
        unsigned int data_len;
        char *data_val;
    } data;
};
typedef struct nfs_fh3 nfs_fh3;

struct nfstime3 {
    uint32 seconds;
    uint32 nseconds;
};
typedef struct nfstime3 nfstime3;

struct fattr3 {
    ftype3 type;
    mode3 mode;
    uint32 nlink;
    uid3 uid;
    gid3 gid;
    size3 size;
    size3 used;
    specdata3 rdev;
    uint64 fsid;
    fileid3 fileid;
    nfstime3 atime;
    nfstime3 mtime;
    nfstime3 ctime;
};
typedef struct fattr3 fattr3;

struct post_op_attr {
    bool_t attributes_follow;
    union {
        fattr3 attributes;
    } post_op_attr_u;
};
typedef struct post_op_attr post_op_attr;

struct wcc_attr {
    size3 size;
    nfstime3 mtime;
    nfstime3 ctime;
};
typedef struct wcc_attr wcc_attr;

struct pre_op_attr {
    bool_t attributes_follow;
    union {
        wcc_attr attributes;
    } pre_op_attr_u;
};
typedef struct pre_op_attr pre_op_attr;

struct wcc_data {
    pre_op_attr before;
    post_op_attr after;
};
typedef struct wcc_data wcc_data;

struct post_op_fh3 {
    bool_t handle_follows;
    union {
        nfs_fh3 handle;
    } post_op_fh3_u;
};
typedef struct post_op_fh3 post_op_fh3;

enum time_how {
    DONT_CHANGE = 0,
    SET_TO_SERVER_TIME = 1,
    SET_TO_CLIENT_TIME = 2
};
typedef enum time_how time_how;

struct set_mode3 {
    bool_t set_it;
    union {
        mode3 mode;
    } set_mode3_u;
};
typedef struct set_mode3 set_mode3;

struct set_uid3 {
    bool_t set_it;
    union {
        uid3 uid;
    } set_uid3_u;
};
typedef struct set_uid3 set_uid3;

struct set_gid3 {
    bool_t set_it;
    union {
        gid3 gid;
    } set_gid3_u;
};
typedef struct set_gid3 set_gid3;

struct set_size3 {
    bool_t set_it;
    union {
        size3 size;
    } set_size3_u;
};
typedef struct set_size3 set_size3;

struct set_atime {
    time_how set_it;
    union {
        nfstime3 atime;
    } set_atime_u;
};
typedef struct set_atime set_atime;

struct set_mtime {
    time_how set_it;
    union {
        nfstime3 mtime;
    } set_mtime_u;
};
typedef struct set_mtime set_mtime;

struct sattr3 {
    set_mode3 mode;
    set_uid3 uid;
    set_gid3 gid;
    set_size3 size;
    set_atime atime;
    set_mtime mtime;
};
typedef struct sattr3 sattr3;

struct diropargs3 {
    nfs_fh3 dir;
    filename3 name;
};
typedef struct diropargs3 diropargs3;

struct GETATTR3args {
    nfs_fh3 object;
};
typedef struct GETATTR3args GETATTR3args;

struct GETATTR3resok {
    fattr3 obj_attributes;
};
typedef struct GETATTR3resok GETATTR3resok;

struct GETATTR3res {
    nfsstat3 status;
    union {
        GETATTR3resok resok;
    } GETATTR3res_u;
};
typedef struct GETATTR3res GETATTR3res;

struct sattrguard3 {
    bool_t check;
    union {
        nfstime3 obj_ctime;
    } sattrguard3_u;
};
typedef struct sattrguard3 sattrguard3;

struct SETATTR3args {
    nfs_fh3 object;
    sattr3 new_attributes;
    sattrguard3 guard;
};
typedef struct SETATTR3args SETATTR3args;

struct SETATTR3resok {
    wcc_data obj_wcc;
};
typedef struct SETATTR3resok SETATTR3resok;

struct SETATTR3resfail {
    wcc_data obj_wcc;
};
typedef struct SETATTR3resfail SETATTR3resfail;

struct SETATTR3res {
    nfsstat3 status;
    union {
        SETATTR3resok resok;
        SETATTR3resfail resfail;
    } SETATTR3res_u;
};
typedef struct SETATTR3res SETATTR3res;

struct LOOKUP3args {
    diropargs3 what;
};
typedef struct LOOKUP3args LOOKUP3args;

struct LOOKUP3resok {
    nfs_fh3 object;
    post_op_attr obj_attributes;
    post_op_attr dir_attributes;
};
typedef struct LOOKUP3resok LOOKUP3resok;

struct LOOKUP3resfail {
    post_op_attr dir_attributes;
};
typedef struct LOOKUP3resfail LOOKUP3resfail;

struct LOOKUP3res {
    nfsstat3 status;
    union {
        LOOKUP3resok resok;
        LOOKUP3resfail resfail;
    } LOOKUP3res_u;
};
typedef struct LOOKUP3res LOOKUP3res;

struct ACCESS3args {
    nfs_fh3 object;
    uint32 access;
};
typedef struct ACCESS3args ACCESS3args;

struct ACCESS3resok {
    post_op_attr obj_attributes;
    uint32 access;
};
typedef struct ACCESS3resok ACCESS3resok;

struct ACCESS3resfail {
    post_op_attr obj_attributes;
};
typedef struct ACCESS3resfail ACCESS3resfail;

struct ACCESS3res {
    nfsstat3 status;
    union {
        ACCESS3resok resok;
        ACCESS3resfail resfail;
    } ACCESS3res_u;
};
typedef struct ACCESS3res ACCESS3res;

struct READLINK3args {
    nfs_fh3 symlink;
};
typedef struct READLINK3args READLINK3args;

struct READLINK3resok {
    post_op_attr symlink_attributes;
    nfspath3 data;
};
typedef struct READLINK3resok READLINK3resok;

struct READLINK3resfail {
    post_op_attr symlink_attributes;
};
typedef struct READLINK3resfail READLINK3resfail;

struct READLINK3res {
    nfsstat3 status;
    union {
        READLINK3resok resok;
        READLINK3resfail resfail;
    } READLINK3res_u;
};
typedef struct READLINK3res READLINK3res;

struct READ3args {
    nfs_fh3 file;
    offset3 offset;
    count3 count;
};
typedef struct READ3args READ3args;

struct READ3resok {
    post_op_attr file_attributes;
    count3 count;
    bool_t eof;
    struct {
        unsigned int data_len;
        char *data_val;
    } data;
};
typedef struct READ3resok READ3resok;

struct READ3resfail {
    post_op_attr file_attributes;
};
typedef struct READ3resfail READ3resfail;

struct READ3res {
    nfsstat3 status;
    union {
        READ3resok resok;
        READ3resfail resfail;
    } READ3res_u;
};
typedef struct READ3res READ3res;

struct WRITE3args {
    nfs_fh3 file;
    offset3 offset;
    count3 count;
    stable_how stable;
    struct {
        unsigned int data_len;
        char *data_val;
    } data;
};
typedef struct WRITE3args WRITE3args;

struct WRITE3resok {
    wcc_data file_wcc;
    count3 count;
    stable_how committed;
    writeverf3 verf;
};
typedef struct WRITE3resok WRITE3resok;

struct WRITE3resfail {
    wcc_data file_wcc;
};
typedef struct WRITE3resfail WRITE3resfail;

struct WRITE3res {
    nfsstat3 status;
    union {
        WRITE3resok resok;
        WRITE3resfail resfail;
    } WRITE3res_u;
};
typedef struct WRITE3res WRITE3res;

struct createhow3 {
    createmode3 mode;
    union {
        sattr3 obj_attributes;
        createverf3 verf;
    } createhow3_u;
};
typedef struct createhow3 createhow3;

struct CREATE3args {
    diropargs3 where;
    createhow3 how;
};
typedef struct CREATE3args CREATE3args;

struct CREATE3resok {
    post_op_fh3 obj;
    post_op_attr obj_attributes;
    wcc_data dir_wcc;
};
typedef struct CREATE3resok CREATE3resok;

struct CREATE3resfail {
    wcc_data dir_wcc;
};
typedef struct CREATE3resfail CREATE3resfail;

struct CREATE3res {
    nfsstat3 status;
    union {
        CREATE3resok resok;
        CREATE3resfail resfail;
    } CREATE3res_u;
};
typedef struct CREATE3res CREATE3res;

struct MKDIR3args {
    diropargs3 where;
    sattr3 attributes;
};
typedef struct MKDIR3args MKDIR3args;

struct MKDIR3resok {
    post_op_fh3 obj;
    post_op_attr obj_attributes;
    wcc_data dir_wcc;
};
typedef struct MKDIR3resok MKDIR3resok;

struct MKDIR3resfail {
    wcc_data dir_wcc;
};
typedef struct MKDIR3resfail MKDIR3resfail;

struct MKDIR3res {
    nfsstat3 status;
    union {
        MKDIR3resok resok;
        MKDIR3resfail resfail;
    } MKDIR3res_u;
};
typedef struct MKDIR3res MKDIR3res;

struct symlinkdata3 {
    sattr3 symlink_attributes;
    nfspath3 symlink_data;
};
typedef struct symlinkdata3 symlinkdata3;

struct SYMLINK3args {
    diropargs3 where;
    symlinkdata3 symlink;
};
typedef struct SYMLINK3args SYMLINK3args;

struct SYMLINK3resok {
    post_op_fh3 obj;
    post_op_attr obj_attributes;
    wcc_data dir_wcc;
};
typedef struct SYMLINK3resok SYMLINK3resok;

struct SYMLINK3resfail {
    wcc_data dir_wcc;
};
typedef struct SYMLINK3resfail SYMLINK3resfail;

struct SYMLINK3res {
    nfsstat3 status;
    union {
        SYMLINK3resok resok;
        SYMLINK3resfail resfail;
    } SYMLINK3res_u;
};
typedef struct SYMLINK3res SYMLINK3res;

struct devicedata3 {
    sattr3 dev_attributes;
    specdata3 spec;
};
typedef struct devicedata3 devicedata3;

struct mknoddata3 {
    ftype3 type;
    union {
        devicedata3 device;
        sattr3 pipe_attributes;
    } mknoddata3_u;
};
typedef struct mknoddata3 mknoddata3;

struct MKNOD3args {
    diropargs3 where;
    mknoddata3 what;
};
typedef struct MKNOD3args MKNOD3args;

struct MKNOD3resok {
    post_op_fh3 obj;
    post_op_attr obj_attributes;
    wcc_data dir_wcc;
};
typedef struct MKNOD3resok MKNOD3resok;

struct MKNOD3resfail {
    wcc_data dir_wcc;
};
typedef struct MKNOD3resfail MKNOD3resfail;

struct MKNOD3res {
    nfsstat3 status;
    union {
        MKNOD3resok resok;
        MKNOD3resfail resfail;
    } MKNOD3res_u;
};
typedef struct MKNOD3res MKNOD3res;

struct REMOVE3args {
    diropargs3 object;
};
typedef struct REMOVE3args REMOVE3args;

struct REMOVE3resok {
    wcc_data dir_wcc;
};
typedef struct REMOVE3resok REMOVE3resok;

struct REMOVE3resfail {
    wcc_data dir_wcc;
};
typedef struct REMOVE3resfail REMOVE3resfail;

struct REMOVE3res {
    nfsstat3 status;
    union {
        REMOVE3resok resok;
        REMOVE3resfail resfail;
    } REMOVE3res_u;
};
typedef struct REMOVE3res REMOVE3res;

struct RMDIR3args {
    diropargs3 object;
};
typedef struct RMDIR3args RMDIR3args;

struct RMDIR3resok {
    wcc_data dir_wcc;
};
typedef struct RMDIR3resok RMDIR3resok;

struct RMDIR3resfail {
    wcc_data dir_wcc;
};
typedef struct RMDIR3resfail RMDIR3resfail;

struct RMDIR3res {
    nfsstat3 status;
    union {
        RMDIR3resok resok;
        RMDIR3resfail resfail;
    } RMDIR3res_u;
};
typedef struct RMDIR3res RMDIR3res;

struct RENAME3args {
    diropargs3 from;
    diropargs3 to;
};
typedef struct RENAME3args RENAME3args;

struct RENAME3resok {
    wcc_data fromdir_wcc;
    wcc_data todir_wcc;
};
typedef struct RENAME3resok RENAME3resok;

struct RENAME3resfail {
    wcc_data fromdir_wcc;
    wcc_data todir_wcc;
};
typedef struct RENAME3resfail RENAME3resfail;

struct RENAME3res {
    nfsstat3 status;
    union {
        RENAME3resok resok;
        RENAME3resfail resfail;
    } RENAME3res_u;
};
typedef struct RENAME3res RENAME3res;

struct LINK3args {
    nfs_fh3 file;
    diropargs3 link;
};
typedef struct LINK3args LINK3args;

struct LINK3resok {
    post_op_attr file_attributes;
    wcc_data linkdir_wcc;
};
typedef struct LINK3resok LINK3resok;

struct LINK3resfail {
    post_op_attr file_attributes;
    wcc_data linkdir_wcc;
};
typedef struct LINK3resfail LINK3resfail;

struct LINK3res {
    nfsstat3 status;
    union {
        LINK3resok resok;
        LINK3resfail resfail;
    } LINK3res_u;
};
typedef struct LINK3res LINK3res;

struct READDIR3args {
    nfs_fh3 dir;
    cookie3 cookie;
    cookieverf3 cookieverf;
    count3 count;
};
typedef struct READDIR3args READDIR3args;

struct entry3 {
    fileid3 fileid;
    filename3 name;
    cookie3 cookie;
    struct entry3 *nextentry;
};
typedef struct entry3 entry3;

struct dirlist3 {
    entry3 *entries;
    bool_t eof;
};
typedef struct dirlist3 dirlist3;

struct READDIR3resok {
    post_op_attr dir_attributes;
    cookieverf3 cookieverf;
    dirlist3 reply;
};
typedef struct READDIR3resok READDIR3resok;

struct READDIR3resfail {
    post_op_attr dir_attributes;
};
typedef struct READDIR3resfail READDIR3resfail;

struct READDIR3res {
    nfsstat3 status;
    union {
        READDIR3resok resok;
        READDIR3resfail resfail;
    } READDIR3res_u;
};
typedef struct READDIR3res READDIR3res;

struct READDIRPLUS3args {
    nfs_fh3 dir;
    cookie3 cookie;
    cookieverf3 cookieverf;
    count3 dircount;
    count3 maxcount;
};
typedef struct READDIRPLUS3args READDIRPLUS3args;

struct entryplus3 {
    fileid3 fileid;
    filename3 name;
    cookie3 cookie;
    post_op_attr name_attributes;
    post_op_fh3 name_handle;
    struct entryplus3 *nextentry;
};
typedef struct entryplus3 entryplus3;

struct dirlistplus3 {
    entryplus3 *entries;
    bool_t eof;
};
typedef struct dirlistplus3 dirlistplus3;

struct READDIRPLUS3resok {
    post_op_attr dir_attributes;
    cookieverf3 cookieverf;
    dirlistplus3 reply;
};
typedef struct READDIRPLUS3resok READDIRPLUS3resok;

struct READDIRPLUS3resfail {
    post_op_attr dir_attributes;
};
typedef struct READDIRPLUS3resfail READDIRPLUS3resfail;

struct READDIRPLUS3res {
    nfsstat3 status;
    union {
        READDIRPLUS3resok resok;
        READDIRPLUS3resfail resfail;
    } READDIRPLUS3res_u;
};
typedef struct READDIRPLUS3res READDIRPLUS3res;

struct FSSTAT3args {
    nfs_fh3 fsroot;
};
typedef struct FSSTAT3args FSSTAT3args;

struct FSSTAT3resok {
    post_op_attr obj_attributes;
    size3 tbytes;
    size3 fbytes;
    size3 abytes;
    size3 tfiles;
    size3 ffiles;
    size3 afiles;
    uint32 invarsec;
};
typedef struct FSSTAT3resok FSSTAT3resok;

struct FSSTAT3resfail {
    post_op_attr obj_attributes;
};
typedef struct FSSTAT3resfail FSSTAT3resfail;

struct FSSTAT3res {
    nfsstat3 status;
    union {
        FSSTAT3resok resok;
        FSSTAT3resfail resfail;
    } FSSTAT3res_u;
};
typedef struct FSSTAT3res FSSTAT3res;

struct FSINFO3args {
    nfs_fh3 fsroot;
};
typedef struct FSINFO3args FSINFO3args;

struct FSINFO3resok {
    post_op_attr obj_attributes;
    uint32 rtmax;
    uint32 rtpref;
    uint32 rtmult;
    uint32 wtmax;
    uint32 wtpref;
    uint32 wtmult;
    uint32 dtpref;
    size3 maxfilesize;
    nfstime3 time_delta;
    uint32 properties;
};
typedef struct FSINFO3resok FSINFO3resok;

struct FSINFO3resfail {
    post_op_attr obj_attributes;
};
typedef struct FSINFO3resfail FSINFO3resfail;

struct FSINFO3res {
    nfsstat3 status;
    union {
        FSINFO3resok resok;
        FSINFO3resfail resfail;
    } FSINFO3res_u;
};
typedef struct FSINFO3res FSINFO3res;

struct PATHCONF3args {
    nfs_fh3 object;
};
typedef struct PATHCONF3args PATHCONF3args;

struct PATHCONF3resok {
    post_op_attr obj_attributes;
    uint32 linkmax;
    uint32 name_max;
    bool_t no_trunc;
    bool_t chown_restricted;
    bool_t case_insensitive;
    bool_t case_preserving;
};
typedef struct PATHCONF3resok PATHCONF3resok;

struct PATHCONF3resfail {
    post_op_attr obj_attributes;
};
typedef struct PATHCONF3resfail PATHCONF3resfail;

struct PATHCONF3res {
    nfsstat3 status;
    union {
        PATHCONF3resok resok;
        PATHCONF3resfail resfail;
    } PATHCONF3res_u;
};
typedef struct PATHCONF3res PATHCONF3res;

struct COMMIT3args {
    nfs_fh3 file;
    offset3 offset;
    count3 count;
};
typedef struct COMMIT3args COMMIT3args;

struct COMMIT3resok {
    wcc_data file_wcc;
    writeverf3 verf;
};
typedef struct COMMIT3resok COMMIT3resok;

struct COMMIT3resfail {
    wcc_data file_wcc;
};
typedef struct COMMIT3resfail COMMIT3resfail;

struct COMMIT3res {
    nfsstat3 status;
    union {
        COMMIT3resok resok;
        COMMIT3resfail resfail;
    } COMMIT3res_u;
};
typedef struct COMMIT3res COMMIT3res;

#define NFS_PROGRAM 100003
#define NFS_V3  3

#define NFSPROC3_NULL   0
extern  enum clnt_stat nfsproc3_null_3(void *, CLIENT *);
#define NFSPROC3_GETATTR    1
extern  enum clnt_stat nfsproc3_getattr_3(GETATTR3args , GETATTR3res *, CLIENT *);
#define NFSPROC3_SETATTR    2
extern  enum clnt_stat nfsproc3_setattr_3(SETATTR3args , SETATTR3res *, CLIENT *);
#define NFSPROC3_LOOKUP 3
extern  enum clnt_stat nfsproc3_lookup_3(LOOKUP3args , LOOKUP3res *, CLIENT *);
#define NFSPROC3_ACCESS 4
extern  enum clnt_stat nfsproc3_access_3(ACCESS3args , ACCESS3res *, CLIENT *);
#define NFSPROC3_READLINK   5
extern  enum clnt_stat nfsproc3_readlink_3(READLINK3args , READLINK3res *, CLIENT *);
#define NFSPROC3_READ   6
extern  enum clnt_stat nfsproc3_read_3(READ3args , READ3res *, CLIENT *);
#define NFSPROC3_WRITE  7
extern  enum clnt_stat nfsproc3_write_3(WRITE3args , WRITE3res *, CLIENT *);
#define NFSPROC3_CREATE 8
extern  enum clnt_stat nfsproc3_create_3(CREATE3args , CREATE3res *, CLIENT *);
#define NFSPROC3_MKDIR  9
extern  enum clnt_stat nfsproc3_mkdir_3(MKDIR3args , MKDIR3res *, CLIENT *);
#define NFSPROC3_SYMLINK    10
extern  enum clnt_stat nfsproc3_symlink_3(SYMLINK3args , SYMLINK3res *, CLIENT *);
#define NFSPROC3_MKNOD  11
extern  enum clnt_stat nfsproc3_mknod_3(MKNOD3args , MKNOD3res *, CLIENT *);
#define NFSPROC3_REMOVE 12
extern  enum clnt_stat nfsproc3_remove_3(REMOVE3args , REMOVE3res *, CLIENT *);
#define NFSPROC3_RMDIR  13
extern  enum clnt_stat nfsproc3_rmdir_3(RMDIR3args , RMDIR3res *, CLIENT *);
#define NFSPROC3_RENAME 14
extern  enum clnt_stat nfsproc3_rename_3(RENAME3args , RENAME3res *, CLIENT *);
#define NFSPROC3_LINK   15
extern  enum clnt_stat nfsproc3_link_3(LINK3args , LINK3res *, CLIENT *);
#define NFSPROC3_READDIR    16
extern  enum clnt_stat nfsproc3_readdir_3(READDIR3args , READDIR3res *, CLIENT *);
#define NFSPROC3_READDIRPLUS    17
extern  enum clnt_stat nfsproc3_readdirplus_3(READDIRPLUS3args , READDIRPLUS3res *, CLIENT *);
#define NFSPROC3_FSSTAT 18
extern  enum clnt_stat nfsproc3_fsstat_3(FSSTAT3args , FSSTAT3res *, CLIENT *);
#define NFSPROC3_FSINFO 19
extern  enum clnt_stat nfsproc3_fsinfo_3(FSINFO3args , FSINFO3res *, CLIENT *);
#define NFSPROC3_PATHCONF   20
extern  enum clnt_stat nfsproc3_pathconf_3(PATHCONF3args , PATHCONF3res *, CLIENT *);
#define NFSPROC3_COMMIT 21
extern  enum clnt_stat nfsproc3_commit_3(COMMIT3args , COMMIT3res *, CLIENT *);

/* the xdr functions */

extern  bool_t xdr_uint64(XDR *, uint64*);
extern  bool_t xdr_int64(XDR *, int64*);
extern  bool_t xdr_uint32(XDR *, uint32*);
extern  bool_t xdr_int32(XDR *, int32*);
extern  bool_t xdr_filename3(XDR *, filename3*);
extern  bool_t xdr_nfspath3(XDR *, nfspath3*);
extern  bool_t xdr_fileid3(XDR *, fileid3*);
extern  bool_t xdr_cookie3(XDR *, cookie3*);
extern  bool_t xdr_cookieverf3(XDR *, cookieverf3);
extern  bool_t xdr_createverf3(XDR *, createverf3);
extern  bool_t xdr_writeverf3(XDR *, writeverf3);
extern  bool_t xdr_uid3(XDR *, uid3*);
extern  bool_t xdr_gid3(XDR *, gid3*);
extern  bool_t xdr_size3(XDR *, size3*);
extern  bool_t xdr_offset3(XDR *, offset3*);
extern  bool_t xdr_mode3(XDR *, mode3*);
extern  bool_t xdr_count3(XDR *, count3*);
extern  bool_t xdr_nfsstat3(XDR *, nfsstat3*);
extern  bool_t xdr_ftype3(XDR *, ftype3*);
extern  bool_t xdr_stable_how(XDR *, stable_how*);
extern  bool_t xdr_createmode3(XDR *, createmode3*);
extern  bool_t xdr_specdata3(XDR *, specdata3*);
extern  bool_t xdr_nfs_fh3(XDR *, nfs_fh3*);
extern  bool_t xdr_nfstime3(XDR *, nfstime3*);
extern  bool_t xdr_fattr3(XDR *, fattr3*);
extern  bool_t xdr_post_op_attr(XDR *, post_op_attr*);
extern  bool_t xdr_wcc_attr(XDR *, wcc_attr*);
extern  bool_t xdr_pre_op_attr(XDR *, pre_op_attr*);
extern  bool_t xdr_wcc_data(XDR *, wcc_data*);
extern  bool_t xdr_post_op_fh3(XDR *, post_op_fh3*);
extern  bool_t xdr_time_how(XDR *, time_how*);
extern  bool_t xdr_set_mode3(XDR *, set_mode3*);
extern  bool_t xdr_set_uid3(XDR *, set_uid3*);
extern  bool_t xdr_set_gid3(XDR *, set_gid3*);
extern  bool_t xdr_set_size3(XDR *, set_size3*);
extern  bool_t xdr_set_atime(XDR *, set_atime*);
extern  bool_t xdr_set_mtime(XDR *, set_mtime*);
extern  bool_t xdr_sattr3(XDR *, sattr3*);
extern  bool_t xdr_diropargs3(XDR *, diropargs3*);
extern  bool_t xdr_GETATTR3args(XDR *, GETATTR3args*);
extern  bool_t xdr_GETATTR3resok(XDR *, GETATTR3resok*);
extern  bool_t xdr_GETATTR3res(XDR *, GETATTR3res*);
extern  bool_t xdr_sattrguard3(XDR *, sattrguard3*);
extern  bool_t xdr_SETATTR3args(XDR *, SETATTR3args*);
extern  bool_t xdr_SETATTR3resok(XDR *, SETATTR3resok*);
extern  bool_t xdr_SETATTR3resfail(XDR *, SETATTR3resfail*);
extern  bool_t xdr_SETATTR3res(XDR *, SETATTR3res*);
extern  bool_t xdr_LOOKUP3args(XDR *, LOOKUP3args*);
extern  bool_t xdr_LOOKUP3resok(XDR *, LOOKUP3resok*);
extern  bool_t xdr_LOOKUP3resfail(XDR *, LOOKUP3resfail*);
extern  bool_t xdr_LOOKUP3res(XDR *, LOOKUP3res*);
extern  bool_t xdr_ACCESS3args(XDR *, ACCESS3args*);
extern  bool_t xdr_ACCESS3resok(XDR *, ACCESS3resok*);
extern  bool_t xdr_ACCESS3resfail(XDR *, ACCESS3resfail*);
extern  bool_t xdr_ACCESS3res(XDR *, ACCESS3res*);
extern  bool_t xdr_READLINK3args(XDR *, READLINK3args*);
extern  bool_t xdr_READLINK3resok(XDR *, READLINK3resok*);
extern  bool_t xdr_READLINK3resfail(XDR *, READLINK3resfail*);
extern  bool_t xdr_READLINK3res(XDR *, READLINK3res*);
extern  bool_t xdr_READ3args(XDR *, READ3args*);
extern  bool_t xdr_READ3resok(XDR *, READ3resok*);
extern  bool_t xdr_READ3resfail(XDR *, READ3resfail*);
extern  bool_t xdr_READ3res(XDR *, READ3res*);
extern  bool_t xdr_WRITE3args(XDR *, WRITE3args*);
extern  bool_t xdr_WRITE3resok(XDR *, WRITE3resok*);
extern  bool_t xdr_WRITE3resfail(XDR *, WRITE3resfail*);
extern  bool_t xdr_WRITE3res(XDR *, WRITE3res*);
extern  bool_t xdr_createhow3(XDR *, createhow3*);
extern  bool_t xdr_CREATE3args(XDR *, CREATE3args*);
extern  bool_t xdr_CREATE3resok(XDR *, CREATE3resok*);
extern  bool_t xdr_CREATE3resfail(XDR *, CREATE3resfail*);
extern  bool_t xdr_CREATE3res(XDR *, CREATE3res*);
extern  bool_t xdr_MKDIR3args(XDR *, MKDIR3args*);
extern  bool_t xdr_MKDIR3resok(XDR *, MKDIR3resok*);
extern  bool_t xdr_MKDIR3resfail(XDR *, MKDIR3resfail*);
extern  bool_t xdr_MKDIR3res(XDR *, MKDIR3res*);
extern  bool_t xdr_symlinkdata3(XDR *, symlinkdata3*);
extern  bool_t xdr_SYMLINK3args(XDR *, SYMLINK3args*);
extern  bool_t xdr_SYMLINK3resok(XDR *, SYMLINK3resok*);
extern  bool_t xdr_SYMLINK3resfail(XDR *, SYMLINK3resfail*);
extern  bool_t xdr_SYMLINK3res(XDR *, SYMLINK3res*);
extern  bool_t xdr_devicedata3(XDR *, devicedata3*);
extern  bool_t xdr_mknoddata3(XDR *, mknoddata3*);
extern  bool_t xdr_MKNOD3args(XDR *, MKNOD3args*);
extern  bool_t xdr_MKNOD3resok(XDR *, MKNOD3resok*);
extern  bool_t xdr_MKNOD3resfail(XDR *, MKNOD3resfail*);
extern  bool_t xdr_MKNOD3res(XDR *, MKNOD3res*);
extern  bool_t xdr_REMOVE3args(XDR *, REMOVE3args*);
extern  bool_t xdr_REMOVE3resok(XDR *, REMOVE3resok*);
extern  bool_t xdr_REMOVE3resfail(XDR *, REMOVE3resfail*);
extern  bool_t xdr_REMOVE3res(XDR *, REMOVE3res*);
extern  bool_t xdr_RMDIR3args(XDR *, RMDIR3args*);
extern  bool_t xdr_RMDIR3resok(XDR *, RMDIR3resok*);
extern  bool_t xdr_RMDIR3resfail(XDR *, RMDIR3resfail*);
extern  bool_t xdr_RMDIR3res(XDR *, RMDIR3res*);
extern  bool_t xdr_RENAME3args(XDR *, RENAME3args*);
extern  bool_t xdr_RENAME3resok(XDR *, RENAME3resok*);
extern  bool_t xdr_RENAME3resfail(XDR *, RENAME3resfail*);
extern  bool_t xdr_RENAME3res(XDR *, RENAME3res*);
extern  bool_t xdr_LINK3args(XDR *, LINK3args*);
extern  bool_t xdr_LINK3resok(XDR *, LINK3resok*);
extern  bool_t xdr_LINK3resfail(XDR *, LINK3resfail*);
extern  bool_t xdr_LINK3res(XDR *, LINK3res*);
extern  bool_t xdr_READDIR3args(XDR *, READDIR3args*);
extern  bool_t xdr_entry3(XDR *, entry3*);
extern  bool_t xdr_dirlist3(XDR *, dirlist3*);
extern  bool_t xdr_READDIR3resok(XDR *, READDIR3resok*);
extern  bool_t xdr_READDIR3resfail(XDR *, READDIR3resfail*);
extern  bool_t xdr_READDIR3res(XDR *, READDIR3res*);
extern  bool_t xdr_READDIRPLUS3args(XDR *, READDIRPLUS3args*);
extern  bool_t xdr_entryplus3(XDR *, entryplus3*);
extern  bool_t xdr_dirlistplus3(XDR *, dirlistplus3*);
extern  bool_t xdr_READDIRPLUS3resok(XDR *, READDIRPLUS3resok*);
extern  bool_t xdr_READDIRPLUS3resfail(XDR *, READDIRPLUS3resfail*);
extern  bool_t xdr_READDIRPLUS3res(XDR *, READDIRPLUS3res*);
extern  bool_t xdr_FSSTAT3args(XDR *, FSSTAT3args*);
extern  bool_t xdr_FSSTAT3resok(XDR *, FSSTAT3resok*);
extern  bool_t xdr_FSSTAT3resfail(XDR *, FSSTAT3resfail*);
extern  bool_t xdr_FSSTAT3res(XDR *, FSSTAT3res*);
extern  bool_t xdr_FSINFO3args(XDR *, FSINFO3args*);
extern  bool_t xdr_FSINFO3resok(XDR *, FSINFO3resok*);
extern  bool_t xdr_FSINFO3resfail(XDR *, FSINFO3resfail*);
extern  bool_t xdr_FSINFO3res(XDR *, FSINFO3res*);
extern  bool_t xdr_PATHCONF3args(XDR *, PATHCONF3args*);
extern  bool_t xdr_PATHCONF3resok(XDR *, PATHCONF3resok*);
extern  bool_t xdr_PATHCONF3resfail(XDR *, PATHCONF3resfail*);
extern  bool_t xdr_PATHCONF3res(XDR *, PATHCONF3res*);
extern  bool_t xdr_COMMIT3args(XDR *, COMMIT3args*);
extern  bool_t xdr_COMMIT3resok(XDR *, COMMIT3resok*);
extern  bool_t xdr_COMMIT3resfail(XDR *, COMMIT3resfail*);
extern  bool_t xdr_COMMIT3res(XDR *, COMMIT3res*);

#ifdef __cplusplus
}
#endif

#endif /* !_NFS_H_RPCGEN */
