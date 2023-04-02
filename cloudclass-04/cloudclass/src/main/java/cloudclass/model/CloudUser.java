package cloudclass.model;

import lombok.Data;

import java.io.Serializable;
import java.util.Date;


/**
 * @author 掘开
 */
@Data
public class CloudUser implements Serializable{
    /**
     * serialVersionUID
     */
    private static final long serialVersionUID = 1L;

    /**
     * userId
     */
    private Long userId;

    /**
     * userName
     */
    private String userName;
    /**
     * userPassword
     */
    private String userPassword;

    /**
     * phone
     */
    private String phone;

    /**
     * email
     */
    private String email;

    /**
     * question
     */
    private String question;

    /**
     * answer
     */
    private String answer;

    /**
     * userAttribute
     */
    private String userAttribute;

    /**
     * createTime
     */
    private Date createTime;

    /**
     * updateTime
     */
    private Date updateTime;


}
