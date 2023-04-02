package cloudclass.service;

import cloudclass.model.CloudUser;

import java.util.List;

/**
 * 用户基本信息表 业务层
 *
 *
 * @author 掘开
 */
public interface CloudUserService {
    /**
     * 所有用户基本信息
     *
     * @return 用户基本信息
     */
    List<CloudUser> selectAll();


}
