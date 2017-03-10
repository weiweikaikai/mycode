kill -TERM `ps -ef | grep " AsyncServ./bench.conf" | grep -v grep | awk '{print $2}'`
sleep 1
./AsynServ ./bench.conf
