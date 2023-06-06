#ifndef BANK_H
#define BANK_H

#define MSGTYPE_OPEN	 (1)	
#define MSGTYPE_DESTROY	 (2)	
#define MSGTYPE_LOGIN	 (3)	
#define MSGTYPE_UNLOCK	 (4)	
#define MSGTYPE_SAVE	 (5)	
#define MSGTYPE_TAKE	 (6)	
#define MSGTYPE_QUERY	 (7)	
#define MSGTYPE_TRANSFER (8)	
#define MSGTYPE_REPASS	 (9)	

//	子进程数量
#define FORK_COUNT (9)

//	可执行文件路径
#define A_OUT_PATH "/home/ubuntu/Linux操作系统/z_bank/bin"

//	账户文件路径 ./.dat

//	账户结构体
typedef struct Account
{
	double balance;		//	余额
	char name[20];		//	姓名
	char id[19];		//	身份证号
	char card_id[20];	//	卡号
	char pass[7];		//	密码
	char is_lock;		//	锁定
}Account;

//	客户端发送的消息结构体
typedef struct CtoS_MSG
{
	long type;		// 	1～9
	Account acc;	//	不能传递帐号结构体指针
	pid_t pid;		//	客户端PID
}CtoS_MSG;

//	服务器发送的消息结构体
typedef struct StoC_MSG
{
	long type;		//	要发送给的客户端的PID
	char info[256];	//	提示信息
}StoC_MSG;



#endif//BANK_H
