return {
    "nvim-treesitter/nvim-treesitter",
    dependencies = {
        "windwp/nvim-ts-autotag"
    },

    build = ':TSUpdate',
    config = function()
        local ts_config = require("nvim-treesitter.configs")

        ts_config.setup({
            ensure_installed = {"vim", "vimdoc", "lua", "cpp", "c", "python"},
            highlight = {enable = true},
            autotag = {
                enable = true
            }
        })
    end
}
