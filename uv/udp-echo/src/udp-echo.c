#include <stdio.h>
#include <stdlib.h>
#include <uv.h>


void alloc_buffer(uv_handle_t *handle, size_t suggested_size,uv_buf_t* buf)
{
    //一次申请,多次使用?
    //2 way to alloc buffer.
    /*
    static char buffer[1024];
    buf->base = buffer;
    buf->len = sizeof(buffer);
     */
    *buf=uv_buf_init((char*) malloc(suggested_size), suggested_size);
}

static void on_send(uv_udp_send_t* req, int status)
{
    free(req);
}

void on_read(uv_udp_t *handle, ssize_t nread, const uv_buf_t* buf, const struct sockaddr* addr, unsigned flags)
{
    uv_udp_send_t* req;
    uv_buf_t sndbuf;

    if(nread<0)
    {
        printf("read error.\r\n");
        free(req);
        return;
    }
    if(nread == 0)
    {
        return;
    }
    char sender[17] = { 0 };
    uv_ip4_name((struct sockaddr_in*) addr, sender, 16);
    printf("Recv from %s:%hu\n", sender,ntohs(((const struct sockaddr_in *)addr)->sin_port));
    req=malloc(sizeof(*req));
    sndbuf=*buf;
    sndbuf.len=nread;
    printf("base:0x%x,size:%lu\r\n",&(sndbuf.base),sndbuf.len);
    uv_udp_send(req,handle,&sndbuf,1,addr,on_send);
    //free(buf);
}


uv_loop_t *loop;
//uv_udp_t send_socket;
uv_udp_t recv_socket;

int main() {
    loop = uv_default_loop();

    uv_udp_init(loop, &recv_socket);
    struct sockaddr_in recv_addr;
    uv_ip4_addr("0.0.0.0", 9999,&recv_addr);
    uv_udp_bind(&recv_socket, (const struct sockaddr *)&recv_addr, 0);
    uv_udp_recv_start(&recv_socket, (uv_alloc_cb)alloc_buffer, (uv_udp_recv_cb)on_read);

    return uv_run(loop, UV_RUN_DEFAULT);
}

