package cloudclass.model;

import lombok.Data;

import java.util.Date;

@Data
public class CloudChooseSystem {
    /**
     * serialVersionUID
     */
    private static final long serialVersionUID = 1L;

    private Long courseId;

    /**
     * subject
     */
    private String subject;

    /**
     * teacher
     */
    private String teacher;

    /**
     * room
     */
    private String room;

    /**
     * course_number
     */
    private Long courseNumber;

    /**
     * begintime
     */
    private Date begintime;

    /**
     * endtime
     */
    private  Date endtime;

    private String createTime;

    private String updateTime;
}
