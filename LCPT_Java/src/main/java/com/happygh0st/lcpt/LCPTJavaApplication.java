package com.happygh0st.lcpt;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@MapperScan("com.happygh0st.lcpt.mapper")
@SpringBootApplication
public class LCPTJavaApplication {
    public static void main(String[] args) {
        SpringApplication.run(LCPTJavaApplication.class, args);
    }
}
