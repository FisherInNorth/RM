-- ----------------------------
-- 张展骞
-- ----------------------------
CREATE TABLE 'payinformation'(
'id' int (11) NOT NULL AUTO_INCREMENT,
'user_id' int (11) DENOT NULL AUTO_INCREMENT,'用户id',
'order_no' bigint(20) DEFAULT NULL COMMENT '订单号',
'price' varchar(50) NOT NULL COMMENT '支付金额',
'pay_platform' int(10) DEFAULT NULL COMMENT '支付平台：1-支付宝，2-微信',
'platform_number' varchar(200) DEFAULT NULL COMMENT '支付宝支付流水号',
'platform_status' varchar(20) DEFAULT NULL COMMENT '支付宝支付状态',
'create_time' datetime DEFAULT NULL COMMENT '创建时间',
'update_time' datetime DEFAULT NULL COMMENT '更新时间',
'price' varchar(50) NOT NULL COMMENT '支付金额',
PRIMARY KEY('id')
)ENGINE=InnoDB AUTO_INCREMENT=53 DEFAULT CHARSET=utf8


-- ----------------------------
-- 秦靖辉
-- ----------------------------
drop table if exists cloud_user;
create table cloud_user
(
     user_id            int(11)         not null auto_increment    comment '用户表id',
     user_name          varchar(50)     not null                   comment '用户名',
     user_password      varchar(50)     not null                   comment '用户密码',
     phone              varchar(20)     default null               comment '电话号码',
     email              varchar(50)     default null               comment '邮箱',
     question           varchar(100)    default null               comment '找回密码问题',
     answer             varchar(100)    default null               comment '找回密码答案',
     user_attribute     int(4)          not null                   comment '属性1-管理员,2-客户',
     create_time        datetime        not null                   comment '创建时间',
     update_time        datetime        not null                   comment '更新时间',
     primary key (user_id)
) engine=innodb auto_increment=21 DEFAULT CHARSET=utf8 comment = '用户表';

-- ----------------------------
-- 慕飒扬
-- ----------------------------
create table class_category(
id int primary key auto_increasement,
parent_id int,
class_name varchar(20),
exist_state boolean default false,
create_by varchar(20),
create_time datetime,
update_by varchar(20),
update_time datetime
);

-- ----------------------------
-- 徐瑞程
-- ----------------------------
CREATE TABLE `cloud_choose`(
  `course_id` INT NOT NULL,
  `subject` CHAR(25) NOT NULL,
  `teacher` CHAR(25) NOT NULL,
  `room` CHAR(25) NOT NULL,
  `course_number` INT NULL,
  `begintime` DATETIME NULL,
  `endtime` DATETIME NULL,
  `create_time` datetime default null,
  `update_time` datetime default null,
  PRIMARY KEY (`course_id`)
  )
ENGINE = InnoDB DEFAULT CHARSET = utf8 COLLATE = utf8_unicode_ci;


-- ----------------------------
-- 夏致远
-- ----------------------------
CREATE TABLE `client_course` (
  `course_id` int(11) NOT NULL AUTO_INCREMENT,
  `subject_chinese` int(11) DEFAULT NULL COMMENT '语文',
  `subject_math` int(11) DEFAULT NULL COMMENT '数学',
  `subject_yingyu` int(11) DEFAULT NULL COMMENT '英语',
  `subject_wuli` int(11) DEFAULT NULL COMMENT '物理',
  `subject_huaxue` int(11) DEFAULT NULL COMMENT '化学',
  `subject_shengwu` int(11) DEFAULT NULL COMMENT '生物',
  `subject_zhengzhi` int(11) DEFAULT NULL COMMENT '政治',
  `subject_lishi` int(11) DEFAULT NULL COMMENT '历史',
  `subject_dili` int(11) DEFAULT NULL COMMENT '地理',
  PRIMARY KEY (`course_id`),
) ENGINE=InnoDB AUTO_INCREMENT=146 DEFAULT CHARSET=utf8;

-- ----------------------------
-- 郭歌
-- ----------------------------
CREATE TABLE `all_class` (
  `id` int NOT NULL AUTO_INCREMENT COMMENT '课程号',
  `subject` varchar(100) NOT NULL COMMENT '课程科目',
  `course_id` varchar(45) NOT NULL,
  `teacher` varchar(100) DEFAULT NULL COMMENT '任课老师',
  `room` varchar(100) DEFAULT NULL COMMENT '上课教室',
  `course_number` varchar(45) DEFAULT NULL,
  `begintime` varchar(200) DEFAULT NULL,
  `endtime` varchar(200) DEFAULT NULL,
  `create_time` datetime DEFAULT NULL,
  `update_time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb3 COMMENT='课程总表 编写者：郭歌';

-- ----------------------------
-- 邓皓文
-- ----------------------------
DROP TABLE IF EXISTS `order information`;
CREATE TABLE `mmall_shipping` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) DEFAULT NULL COMMENT '用户id',
  `receiver_name` varchar(20) DEFAULT NULL COMMENT '收货姓名',
  `receiver_phone` varchar(20) DEFAULT NULL COMMENT '收货固定电话',
  `receiver_mobile` varchar(20) DEFAULT NULL COMMENT '收货移动电话',
  `receiver_province` varchar(20) DEFAULT NULL COMMENT '省份',
  `receiver_city` varchar(20) DEFAULT NULL COMMENT '城市',
  `receiver_district` varchar(20) DEFAULT NULL COMMENT '区/县',
  `receiver_address` varchar(200) DEFAULT NULL COMMENT '详细地址',
  `receiver_zip` varchar(6) DEFAULT NULL COMMENT '邮编',
  `create_time` datetime DEFAULT NULL,
  `update_time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=33 DEFAULT CHARSET=utf8;