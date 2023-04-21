<template>
    <div class="container">
        <h1>{{page.pageTitle}}</h1>
        <p>{{page.subTitle}}</p>
        <component :is="currentPageComponent"></component>
    </div>
</template>

<script>
    export default{
        name: 'page-viewer',
        props: {
            page:{
                    type: Object,
                    required: true
                }
        },
        computed: {
            currentPageComponent() {
            return this.page.components ? this.page.components[this.page.pageTitle.replace(/\s/g, '')] : null;
            }
        }
}
</script>








