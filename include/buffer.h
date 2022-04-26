

typedef struct liBuffer liBuffer;

struct vega_buffer {
	gchar *addr;
	gsize alloc_size;
	gsize used;
	gint refcount;
	liMempoolPtr mptr;
};
