FROM gcc

WORKDIR /app/
COPY . .
RUN make
EXPOSE 1024-60000
CMD ["./server"]