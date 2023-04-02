package cloudclass.model;

import lombok.Data;

import java.io.Serializable;

/**
 * @author 掘开
 */
@Data
public class AllClass implements Serializable {

    private Long id;

    private String subject;

    private String courseId;

    private String teacher;

    private String room;

    private String courseNumber;

    private String begintime;

    private String endtime;

    private String createTime;

    private String updateTime;


}
