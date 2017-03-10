kill -TERM `ps -ef | grep "AsynServ ./bench.conf" | grep -v grep | awk '{print $2}'`
sleep 1
./AsynServ ./bench.conf
