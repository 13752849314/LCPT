package com.happygh0st.lcpt.commons;

import lombok.Data;

import java.util.HashMap;
import java.util.Map;

@Data
public class Results {
    private Integer code;
    private String message;
    private Map<String, Object> data;

    public Results() {
        this.data = new HashMap<>();
    }

    public Results(Integer code, String message) {
        this.code = code;
        this.message = message;
        this.data = new HashMap<>();
    }

    public static Results success() {
        return new Results(200, "操作成功");
    }

    public static Results failed(String message) {
        return new Results(400, message);
    }

    public Results addData(String key, Object value) {
        data.put(key, value);
        return this;
    }
}
