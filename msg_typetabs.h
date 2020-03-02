/* This is a generated file, see Makefile.am for its inputs. */
static const char msg_type_strings[] = "ADD_GROUP\0ADD_USER\0ANOM_ABEND\0ANOM_ACCESS_FS\0ANOM_ADD_ACCT\0ANOM_AMTU_FAIL\0ANOM_CRYPTO_FAIL\0ANOM_DEL_ACCT\0ANOM_EXEC\0ANOM_LOGIN_ACCT\0"
	"ANOM_LOGIN_FAILURES\0ANOM_LOGIN_LOCATION\0ANOM_LOGIN_SESSIONS\0ANOM_LOGIN_TIME\0ANOM_MAX_DAC\0ANOM_MAX_MAC\0ANOM_MK_EXEC\0ANOM_MOD_ACCT\0ANOM_PROMISCUOUS\0ANOM_RBAC_FAIL\0"
	"ANOM_RBAC_INTEGRITY_FAIL\0ANOM_ROOT_TRANS\0AVC\0AVC_PATH\0BPRM_FCAPS\0CAPSET\0CHGRP_ID\0CHUSER_ID\0CONFIG_CHANGE\0CRED_ACQ\0"
	"CRED_DISP\0CRED_REFR\0CRYPTO_FAILURE_USER\0CRYPTO_KEY_USER\0CRYPTO_LOGIN\0CRYPTO_LOGOUT\0CRYPTO_PARAM_CHANGE_USER\0CRYPTO_REPLAY_USER\0CRYPTO_SESSION\0CRYPTO_TEST_USER\0"
	"CWD\0DAC_CHECK\0DAEMON_ABORT\0DAEMON_ACCEPT\0DAEMON_CLOSE\0DAEMON_CONFIG\0DAEMON_END\0DAEMON_RESUME\0DAEMON_ROTATE\0DAEMON_START\0"
	"DEL_GROUP\0DEL_USER\0DEV_ALLOC\0DEV_DEALLOC\0EOE\0EXECVE\0FD_PAIR\0FS_RELABEL\0GRP_AUTH\0INTEGRITY_DATA\0"
	"INTEGRITY_HASH\0INTEGRITY_METADATA\0INTEGRITY_PCR\0INTEGRITY_RULE\0INTEGRITY_STATUS\0IPC\0IPC_SET_PERM\0KERNEL\0KERNEL_OTHER\0LABEL_LEVEL_CHANGE\0"
	"LABEL_OVERRIDE\0LIST_RULES\0LOGIN\0MAC_CIPSOV4_ADD\0MAC_CIPSOV4_DEL\0MAC_CONFIG_CHANGE\0MAC_IPSEC_ADDSA\0MAC_IPSEC_ADDSPD\0MAC_IPSEC_DELSA\0MAC_IPSEC_DELSPD\0"
	"MAC_IPSEC_EVENT\0MAC_MAP_ADD\0MAC_MAP_DEL\0MAC_POLICY_LOAD\0MAC_STATUS\0MAC_UNLBL_ALLOW\0MAC_UNLBL_STCADD\0MAC_UNLBL_STCDEL\0MMAP\0MQ_GETSETATTR\0"
	"MQ_NOTIFY\0MQ_OPEN\0MQ_SENDRECV\0NETFILTER_CFG\0NETFILTER_PKT\0OBJ_PID\0PATH\0RESP_ACCT_LOCK\0RESP_ACCT_LOCK_TIMED\0RESP_ACCT_REMOTE\0"
	"RESP_ACCT_UNLOCK_TIMED\0RESP_ALERT\0RESP_ANOMALY\0RESP_EXEC\0RESP_HALT\0RESP_KILL_PROC\0RESP_SEBOOL\0RESP_SINGLE\0RESP_TERM_ACCESS\0RESP_TERM_LOCK\0"
	"ROLE_ASSIGN\0ROLE_REMOVE\0SELINUX_ERR\0SERVICE_START\0SERVICE_STOP\0SOCKADDR\0SOCKETCALL\0SYSCALL\0SYSTEM_BOOT\0SYSTEM_RUNLEVEL\0"
	"SYSTEM_SHUTDOWN\0TEST\0TRUSTED_APP\0TTY\0TTY_GET\0TTY_SET\0USER\0USER_ACCT\0USER_AUTH\0USER_AVC\0"
	"USER_CHAUTHTOK\0USER_CMD\0USER_END\0USER_ERR\0USER_LABELED_EXPORT\0USER_LOGIN\0USER_LOGOUT\0USER_MAC_POLICY_LOAD\0USER_MGMT\0USER_ROLE_CHANGE\0"
	"USER_SELINUX_ERR\0USER_START\0USER_TTY\0USER_UNLABELED_EXPORT\0USYS_CONFIG\0VIRT_CONTROL\0VIRT_MACHINE_ID\0VIRT_RESOURCE";
static const unsigned msg_type_s2i_s[] = {
	0,10,19,30,45,59,74,91,105,115,
	131,151,171,191,207,220,233,246,260,277,
	292,317,333,337,346,357,364,373,383,397,
	406,416,426,446,462,475,489,514,533,548,
	565,569,579,592,606,619,633,644,658,672,
	685,695,704,714,726,730,737,745,756,765,
	780,795,814,828,843,860,864,877,884,897,
	916,931,942,948,964,980,998,1014,1031,1047,
	1064,1080,1092,1104,1120,1131,1147,1164,1181,1186,
	1200,1210,1218,1230,1244,1258,1266,1271,1286,1307,
	1324,1347,1358,1371,1381,1391,1406,1418,1430,1447,
	1462,1474,1486,1498,1512,1525,1534,1545,1553,1565,
	1581,1597,1602,1614,1618,1626,1634,1639,1649,1659,
	1668,1683,1692,1701,1710,1730,1741,1753,1774,1784,
	1801,1818,1829,1838,1860,1872,1885,1901,
};
static const int msg_type_s2i_i[] = {
	1116,1114,1701,2111,2114,2107,2110,2115,2112,2103,
	2100,2104,2102,2101,2105,2106,2113,2116,1700,2108,
	2109,2117,1400,1402,1321,1322,1119,1125,1305,1103,
	1104,1110,2405,2404,2402,2403,2401,2406,2407,2400,
	1307,1118,1202,1207,1208,1203,1201,1206,1205,1200,
	1117,1115,2307,2308,1320,1309,1317,2309,1126,1800,
	1803,1801,1804,1805,1802,1303,1311,2000,1316,2304,
	2303,1013,1006,1407,1408,1405,1411,1413,1412,1414,
	1415,1409,1410,1403,1404,1406,1416,1417,1323,1315,
	1314,1312,1313,1325,1324,1318,1302,2207,2205,2204,
	2206,2201,2200,2210,2212,2202,2209,2211,2203,2208,
	2301,2302,1401,1130,1131,1306,1304,1300,1127,1129,
	1128,1120,1121,1319,1016,1017,1005,1101,1100,1107,
	1108,1123,1106,1109,2305,1112,1113,2310,1102,2300,
	1122,1105,1124,2306,1111,2500,2502,2501,
};
static int msg_type_s2i(const char *s, int *value) {
	size_t len, i;
	len = strlen(s);
	{ char copy[len + 1];
	for (i = 0; i < len; i++) {
		char c = s[i];
		copy[i] = GT_ISLOWER(c) ? c - 'a' + 'A' : c;
	}
	copy[i] = 0;
	return s2i__(msg_type_strings, msg_type_s2i_s, msg_type_s2i_i, 148, copy, value);
	}
}
static const int msg_type_i2s_i[] = {
	1005,1006,1013,1016,1017,1100,1101,1102,1103,1104,
	1105,1106,1107,1108,1109,1110,1111,1112,1113,1114,
	1115,1116,1117,1118,1119,1120,1121,1122,1123,1124,
	1125,1126,1127,1128,1129,1130,1131,1200,1201,1202,
	1203,1205,1206,1207,1208,1300,1302,1303,1304,1305,
	1306,1307,1309,1311,1312,1313,1314,1315,1316,1317,
	1318,1319,1320,1321,1322,1323,1324,1325,1400,1401,
	1402,1403,1404,1405,1406,1407,1408,1409,1410,1411,
	1412,1413,1414,1415,1416,1417,1700,1701,1800,1801,
	1802,1803,1804,1805,2000,2100,2101,2102,2103,2104,
	2105,2106,2107,2108,2109,2110,2111,2112,2113,2114,
	2115,2116,2117,2200,2201,2202,2203,2204,2205,2206,
	2207,2208,2209,2210,2211,2212,2300,2301,2302,2303,
	2304,2305,2306,2307,2308,2309,2310,2400,2401,2402,
	2403,2404,2405,2406,2407,2500,2501,2502,
};
static const unsigned msg_type_i2s_s[] = {
	1634,942,931,1618,1626,1649,1639,1774,397,406,
	1818,1692,1659,1668,1701,416,1860,1730,1741,10,
	695,0,685,569,364,1597,1602,1801,1683,1829,
	373,756,1553,1581,1565,1498,1512,672,633,579,
	619,658,644,592,606,1545,1266,860,1534,383,
	1525,565,730,864,1210,1218,1200,1186,884,737,
	1258,1614,726,346,357,1181,1244,1230,333,1486,
	337,1104,1120,980,1131,948,964,1080,1092,998,
	1031,1014,1047,1064,1147,1164,260,19,765,795,
	843,780,814,828,877,131,191,171,115,151,
	207,220,59,277,292,74,30,105,233,45,
	91,246,317,1358,1347,1391,1430,1307,1286,1324,
	1271,1447,1406,1371,1418,1381,1784,1462,1474,916,
	897,1710,1838,704,714,745,1753,548,489,462,
	475,446,426,514,533,1872,1901,1885,
};
static const char *msg_type_i2s(int v) {
	return i2s_bsearch__(msg_type_strings, msg_type_i2s_i, msg_type_i2s_s, 148, v);
}
