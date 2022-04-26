

typedef struct liBuffer liBuffer;

class vega_buffer {
	private:
		gchar *addr;
		gsize alloc_size;
		gsize used;
		gint refcount;
		liMempoolPtr mptr;
};
