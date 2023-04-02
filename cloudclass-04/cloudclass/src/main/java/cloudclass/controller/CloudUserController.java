package cloudclass.controller;

import cloudclass.model.CloudUser;
import cloudclass.service.CloudUserService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("cloudclass-04/user")
@Slf4j

public class CloudUserController {
    @Autowired
    private CloudUserService cloudUserService;

    @GetMapping("list")
    public List<CloudUser> list() {

        List<CloudUser> list = cloudUserService.selectAll();
        return list;
    }
}
