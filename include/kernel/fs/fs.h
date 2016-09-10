#ifndef GENOS_FILE_H
#define GENOS_FILE_H

#include <defines/off_t.h>
#include <defines/size_t.h>
#include <defines/ssize_t.h>

struct file;
struct file_operations;
struct inode; 
struct dentry;

struct file {
  off_t				f_pos;      /* File position */ 
  struct inode* 	f_inode;    /* Driver interface */
  void*				f_priv;     /* Per file driver private data */
};

struct file_operations {
	int 	(*open)		(struct file *filep);
	int     (*close)	(struct file *filep);
	ssize_t (*read)		(struct file *filep, char *buffer, size_t buflen);
	ssize_t (*write)	(struct file *filep, const char *buffer, size_t buflen);
	off_t   (*seek)		(struct file *filep, off_t offset, int whence);
	int     (*ioctl)	(struct file *filep, int cmd, unsigned long arg);
};

union inode_ops_u
{
  	const struct file_operations      	*i_ops;    /* Driver operations for inode */
  	//const struct block_operations     *i_bops;   /* Block driver operations */
  	//const struct mountpt_operations   *i_mops;   /* Operations on a mountpoint */
	//const struct nsem_inode_s         *i_nsem;   /* Named semaphore */
  	//const struct mqueue_inode_s         *i_mqueue; /* POSIX message queue */
};

struct inode_proto
{
	struct inode*           i_peer;     /* Link to same level inode */
	struct inode*           i_child;    /* Link to lower level inode */
	int16_t                 i_crefs;    /* References to inode */
  //uint16_t                i_flags;    /* Flags for inode */
	union inode_ops_u  		u;	        /* Inode operations */

  	void*                   i_private;  /* Per inode driver private data */
  	char                    i_name[1];  /* Name of inode (variable) */
};

struct dentry {

};

#endif